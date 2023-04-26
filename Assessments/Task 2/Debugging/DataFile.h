#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class DataFile
{
public:
	struct Record {
		Image image;
		string name;
		int age;
	};

private:
	int recordCount;
	vector<Record*> records;	// delete this vector. Load only the required record 

public:
	DataFile();
	~DataFile();

	void AddRecord(string _imageFilename, string _name, int _age);
	Record* GetRecord(int _index);

	int GetRecordCount() { return recordCount; }

	void Save(string _filename);
	void Load(string _filename);

private:
	void Clear();

};

