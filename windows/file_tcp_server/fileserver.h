#pragma once

#include <string>
#include <vector>

using namespace std;

class FileServer
{
public:
	FileServer(const string& dirPath);
	~FileServer();

	vector<string> getFileNames();
	void upLoadStreamDataToFile(char* srcfileStream, const string& dstFileName);
	void downLoadFileToStreamData(const string& srcfileName, char* dstFileStream);
	bool existFile(const string& fileName);
};
