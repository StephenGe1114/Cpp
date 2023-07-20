 ///
 /// @file    1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
/*文本查询
  该程序将读取用户指定的任意文本文件【当前目录下的china_daily.txt】,然后允许用户从该文件中查找单词。查询的结果是该单词出现的次数，并列出每次出现所在的行。如果某单词在同一行中多次出现，程序将只显示该行一次。行号按升序显示。
  要求：
  a. 它必须允许用户指明要处理的文件名字。
  b. 程序将存储该文件的内容，以便输出每个单词所在的原始行。
     vector<string> lines;//O(1)  完美hash
     或 map<int, string> lines;//O(logN)
     或 unorderedmap<int,string> lines;//O(1)
  c. 它必须将每一行分解为各个单词，并记录每个单词所在的所有行。在输出行号时，应保证以升序输出，并且不重复。
     map<string, set<int> > word2Line;
     map<string, int> dict;
  d. 对特定单词的查询将返回出现该单词的所有行的行号。
  e. 输出某单词所在的行文本时，程序必须能根据给定的行号从输入文件中获取相应的行。
  示例：
      使用提供的文件内容，然后查找单词 "element"。输出的前几行为：
      ---------------------------------------------
      element occurs 125 times.
      (line 62) element with a given key.
      (line 64) second element with the same key.
      (line 153) element |==| operator.
      (line 250) the element type.
      (line 398) corresponding element.
      ---------------------------------------------
      程序接口[可选]:
      class TextQuery
      {
      public:
      void readFile(const string filename);
      void query(const string & word);
      private:
      //......
      };

      //程序测试用例
      int main(int argc, char *argv[])
      {
          string  queryWord("hello");
          TextQuery tq;
          tq.readFile("test.dat");
          tq.query(queryWord);
          return 0;
      }     			*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::string;
using std::vector;

class TextQuery
{
public:
    void readFile(const string filename);

    void query(const string &word);

private:
    void preprocessed(string &line)
    {
        for (auto &c : line)
        {
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            {
            }
            else
            {
                c = ' ';
            }
        }
    }

private:
    vector<string> _lines;
    map<string, set<int>> _wordLine;
    map<string, int> _wordFrequency;
};

void TextQuery::readFile(const string filename)
{
    ifstream ifs(filename);
    if (!ifs)
    {
        cout << "open file error" << endl;
        return;
    }
    string line;
    while (getline(ifs, line))
    {
        _lines.push_back(line);
        preprocessed(line);
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            ++_wordFrequency[word];
            _wordLine[word].insert(_lines.size());
        }
    }
}

void TextQuery::query(const string &word)
{
    auto it = _wordFrequency.find(word);
    if (it != _wordFrequency.end())
    {
        cout << word << " occurs " << _wordFrequency[word] << " times." << endl;
        for (auto mem : _wordLine[word])
        {
            cout << "(line " << mem << ") " << _lines[mem - 1] << endl;
        }
    }
    else
    {
        cout << word << " occurs 0 times." << endl;
    }
}

int main(int argc, char *argv[])
{
    string queryWord("with");
    TextQuery tq;
    tq.readFile("china_daily.txt");
    tq.query(queryWord);
    return 0;
}
