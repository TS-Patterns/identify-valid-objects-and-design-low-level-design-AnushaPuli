#include "iostream"
#include <list>
#include <algorithm>

using namespace std;

class Paragraph;
class HyperLink;

class IDocConvertor
{
public:
    virtual void ConvertParagraph(Paragraph par) = 0;
    virtual void ConvertHyperLink(HyperLink hyp) = 0;
};

class DocumentPart
{
public:
    virtual void Convert(IDocConvertor* convertor) = 0;

};

class Paragraph : public DocumentPart
{
public:
    void Convert(IDocConvertor* convertor)
    {
        convertor->ConvertParagraph(*this);
    }

};
class HyperLink : public DocumentPart
{
public:
    void Convert(IDocConvertor* convertor)
    {
        convertor->ConvertHyperLink(*this);
    }
};


class Document
{
    list<DocumentPart*> list;
public:
    void Add(DocumentPart* doc)
    {
        list.push_back(doc);
    }
    void Convert(IDocConvertor* convertor)
    {
        for (auto it = list.begin(); it != list.end(); it++)
        {
            (*it)->Convert(convertor);
        }
    }
};

class SXPSConvertor : public IDocConvertor
{
public:
    void ConvertParagraph(Paragraph par)
    {
        cout << "ConvertParagraph called in SXPSConvertor" << endl;
    }
    void ConvertHyperLink(HyperLink hyp)
    {
        cout << "ConvertParagraph called in SXPSConvertor" << endl;

    }
};
class PDFConvertor : public IDocConvertor
{
public:
    void ConvertParagraph(Paragraph par)
    {
        cout << "ConvertParagraph called in PDFConvertor" << endl;
    }
    void ConvertHyperLink(HyperLink hyp)
    {
        cout << "ConvertHyperLink called in PDFConvertor" << endl;

    }
};

int main()
{
    Document* obj = new Document();
    obj->Add(new Paragraph());
    obj->Add(new HyperLink());

    obj->Convert(new PDFConvertor());
    std::getchar();
    return 0;
}