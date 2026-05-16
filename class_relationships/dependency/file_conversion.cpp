#include <iostream>
#include <string>
using namespace std;

class FileReader
{
public:
    string read(const string &filePath)
    {
        cout << "Reading file: " << filePath << endl;
        string content = "name,age,city";
        cout << "Content: " << content << endl;
        return content;
    }
};

class FormatParser
{
public:
    string parse(const string &content, const string &targetFormat)
    {
        cout << "Parsing content to " << targetFormat << " format" << endl;
        string parsed = "[{\"name\":\"Alice\",\"age\":30,\"city\":\"NYC\"}]";
        cout << "Parsed: " << parsed << endl;
        return parsed;
    }
};

class FileWriter
{
public:
    void write(const string &filePath, const string &content)
    {
        cout << "Writing to file: " << filePath << endl;
    }
};

class FileConverter
{
public:
    void convert(const string &sourcePath, const string &targetPath,
                 const string &targetFormat, FileReader &reader,
                 FormatParser &parser, FileWriter &writer)
    {
        string content = reader.read(sourcePath);
        string parsed = parser.parse(content, targetFormat);
        writer.write(targetPath, parsed);
        cout << "File conversion complete: " << sourcePath << " -> " << targetPath << endl;
    }
};

int main()
{
    FileConverter converter;

    FileReader reader;
    FormatParser parser;
    FileWriter writer;

    converter.convert("data.csv", "output.json", "JSON", reader, parser, writer);

    return 0;
}