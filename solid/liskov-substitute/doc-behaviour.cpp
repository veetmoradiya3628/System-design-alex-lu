#include <bits/stdc++.h>
using namespace std;

class Document
{
public:
    virtual void open() const = 0;
    virtual string getData() const = 0;
    virtual ~Document() = default;
};

class Editable : public Document
{
public:
    virtual void save(const string &newData) = 0;
};

class EditableDocument : public Editable
{
private:
    string data;

    string preview() const
    {
        return data.substr(0, min((size_t)20, data.length())) + "...";
    }

public:
    EditableDocument(const string &data) : data(data) {}

    void open() const override
    {
        cout << "Editable Document opened. Data: " << preview() << endl;
    }

    void save(const string &newData) override
    {
        data = newData;
        cout << "Document saved." << endl;
    }

    string getData() const override
    {
        return data;
    }
};
class ReadOnlyDocument : public Document
{
private:
    string data;

    string preview() const
    {
        return data.substr(0, min((size_t)20, data.length())) + "...";
    }

public:
    ReadOnlyDocument(const string &data) : data(data) {}

    void open() const override
    {
        cout << "Read-Only Document opened. Data: " << preview() << endl;
    }

    string getData() const override
    {
        return data;
    }
};

class DocumentProcessor
{
public:
    void process(const Document *doc) const
    {
        doc->open();
        cout << "Document processed." << endl;
    }

    void processAndSave(Editable &doc, const string &additionalInfo)
    {
        doc.open();
        string currentData = doc.getData();
        string newData = currentData + " | Processed: " + additionalInfo;
        doc.save(newData);
        cout << "Editable document processed and saved." << endl;
    }
};
int main()
{
    EditableDocument editable("Draft proposal for Q3.");
    ReadOnlyDocument readOnly("Top secret strategy.");
    DocumentProcessor processor;

    cout << "--- Processing Editable Document ---" << endl;
    processor.processAndSave(editable, "Reviewed by Alice");

    cout << "\n--- Processing Read-Only Document ---" << endl;
    processor.process(&readOnly); // Works fine

    // processor.processAndSave(readOnly, "Reviewed by Bob");
    // Won't compile! ReadOnlyDocument doesn't have save().

    return 0;
}