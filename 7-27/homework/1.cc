 ///
 /// @file    1.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   
/*
统计一篇英文(The_Holy_Bible.txt)文章中出现的单词和词频，
   输入：某篇文章的绝对路径
   输出：词典（词典中的内容为每一行都是一个“单词 词频”）

   词典的存储格式如下
 -----------------
|   a 66          |
|   abandon 77    |
|   public 88     |
|    ......	      |
|_________________|

    class Dictionary
    {
    public:
            //......
        void read(const std::string & filename);
        void store(const std::string & filename);
    private:
        //......
    };
       */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::ofstream;
using std::string;

class Dictionary
{
public:
    void read(const string &filename);
    void store(const string &filename);

private:
    map<string, int> _dict;
};

void Dictionary::read(const string &filename)
{
    ifstream ifs(filename);
    if (!ifs)
    {
        cout << " ifstream open error!" << endl;
        return;
    }
    string line;
    while (std::getline(ifs, line))
    {
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            if (word[0] >= 48 && word[0] <= 57)
            {
                continue;
            }
            ++_dict[word];
        }
    }
    ifs.close();
}

void Dictionary::store(const string &filename)
{
    ofstream ofs(filename);
    for (auto it = _dict.begin(); it != _dict.end(); ++it)
    {
        ofs << it->first << " " << it->second << endl;
    }
    ofs.close();
}

int main()
{
    Dictionary dict;
    dict.read("The_Holy_Bible.txt");
    dict.store("file.txt");
    return 0;
}

