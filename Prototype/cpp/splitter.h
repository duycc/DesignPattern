#ifndef __SPLITTER_H__
#define __SPLITTER_H__

#include <iostream>

class ISplitter {
public:
    virtual ~ISplitter() {}

    virtual void Split() = 0;
    virtual ISplitter* Clone() = 0;
};

class BinarySplitter : public ISplitter {
public:
    void Split() { std::cout << "binary split..." << std::endl; }
    ISplitter* Clone() { return new BinarySplitter(*this); }
};

class TextSplitter : public ISplitter {
public:
    void Split() { std::cout << "binary text..." << std::endl; }
    ISplitter* Clone() { return new TextSplitter(*this); }
};

class PictureSplitter : public ISplitter {
public:
    void Split() { std::cout << "picture split..." << std::endl; }
    ISplitter* Clone() { return new PictureSplitter(*this); }
};

class VideoSplitter : public ISplitter {
public:
    void Split() { std::cout << "video split..." << std::endl; }
    ISplitter* Clone() { return new VideoSplitter(*this); }
};

#endif // __SPLITTER_H__