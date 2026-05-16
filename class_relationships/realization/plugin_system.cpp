#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Plugin
{
public:
    virtual string execute(const string &text) = 0;
    virtual string getName() = 0;
    virtual ~Plugin() = default;
};

class SpellCheckPlugin : public Plugin
{
public:
    string execute(const string &text) override
    {
        string result = text;
        size_t pos;
        while ((pos = result.find("teh")) != string::npos)
        {
            result.replace(pos, 3, "the");
        }
        while ((pos = result.find("adn")) != string::npos)
        {
            result.replace(pos, 3, "and");
        }
        return result;
    }

    string getName() override
    {
        return "Spell Check";
    }
};

class WordCountPlugin : public Plugin
{
public:
    string execute(const string &text) override
    {
        istringstream stream(text);
        string word;
        int count = 0;
        while (stream >> word)
        {
            count++;
        }
        return text + "\n[Word count: " + to_string(count) + "]";
    }

    string getName() override
    {
        return "Word Count";
    }
};

class UpperCasePlugin : public Plugin
{
public:
    string execute(const string &text) override
    {
        string result = text;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    string getName() override
    {
        return "Upper Case";
    }
};

class TextEditor
{
    vector<unique_ptr<Plugin>> plugins;

public:
    void registerPlugin(unique_ptr<Plugin> plugin)
    {
        cout << "Registered: " << plugin->getName() << endl;
        plugins.push_back(move(plugin));
    }

    string runPlugins(const string &text)
    {
        string result = text;
        for (auto &plugin : plugins)
        {
            cout << "Running: " << plugin->getName() << endl;
            result = plugin->execute(result);
        }
        return result;
    }
};

int main()
{
    TextEditor editor;
    editor.registerPlugin(make_unique<SpellCheckPlugin>());
    editor.registerPlugin(make_unique<WordCountPlugin>());

    string result = editor.runPlugins("teh quick brown fox adn teh lazy dog");
    cout << "\nFinal output: " << result << endl;

    return 0;
}