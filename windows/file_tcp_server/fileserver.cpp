#include "fileserver.h"

FileServer::FileServer(const string & dirPath)
{
}

FileServer::~FileServer()
{
}

vector<string> FileServer::getFileNames()
{
	return vector<string>();
}

void FileServer::upLoadStreamDataToFile(char * srcfileStream, const string & dstFileName)
{
}

void FileServer::downLoadFileToStreamData(const string & srcfileName, char * dstFileStream)
{
}

bool FileServer::existFile(const string & fileName)
{
	return false;
}
