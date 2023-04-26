#include "DataFile.h"
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::ios;

Image LoadImageEx(Color* _pixels, int _width, int _height)
{
	Image image = { 0 };
	image.data = NULL;
	image.width = _width;
	image.height = _height;
	image.mipmaps = 1;
	image.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;

	int k = 0;

	image.data = (unsigned char*)RL_MALLOC(image.width * image.height * 4 * sizeof(unsigned char));

	for (int i = 0; i < image.width * image.height * 4; i += 4)
	{
		((unsigned char*)image.data)[i] = _pixels[k].r;
		((unsigned char*)image.data)[i + 1] = _pixels[k].g;
		((unsigned char*)image.data)[i + 2] = _pixels[k].b;
		((unsigned char*)image.data)[i + 3] = _pixels[k].a;
		k++;
	}

	return image;
}

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	Clear();
}

void DataFile::AddRecord(string _imageFilename, string _name, int _age)
{
	Image i = LoadImage(_imageFilename.c_str());

	Record* r = new Record;
	r->image = i;
	r->name = _name;
	r->age = _age;

	records.push_back(r);
	recordCount++;
}

DataFile::Record* DataFile::GetRecord(int _index)
{
	return records[_index];
}

void DataFile::Save(string _filename)
{
	ofstream outfile(_filename, ios::binary);

	size_t recordCount = records.size();
	outfile.write((char*)&recordCount, sizeof(int));

	for (int i = 0; i < recordCount; i++)
	{
		Color* imgdata = (Color*)records[i]->image.data;

		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
		size_t nameSize = records[i]->name.length();
		int ageSize = sizeof(int);

		outfile.write((char*)&records[i]->image.width, sizeof(int));
		outfile.write((char*)&records[i]->image.height, sizeof(int));

		outfile.write((char*)&nameSize, sizeof(int));
		outfile.write((char*)&ageSize, sizeof(int));

		outfile.write((char*)imgdata, imageSize);
		outfile.write((char*)records[i]->name.c_str(), nameSize);
		outfile.write((char*)&records[i]->age, ageSize);
	}

	outfile.close();
}

void DataFile::Load(string _filename)
{
	Clear();

	ifstream infile(_filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	for (int i = 0; i < recordCount; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		char* imgdata = new char[imageSize];
		infile.read(imgdata, imageSize);

		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize];
		int age = 0;

		infile.read((char*)name, nameSize);
		infile.read((char*)&age, ageSize);

		Record* r = new Record();
		r->image = img;
		r->name = string(name);
		r->age = age;
		records.push_back(r);

		delete[] imgdata;
		delete[] name;
	}

	infile.close();
}

void DataFile::Clear()
{
	for (int i = 0; i < records.size(); i++)
	{
		delete records[i];
	}
	records.clear();
	recordCount = 0;
}