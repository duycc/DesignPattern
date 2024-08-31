
#include "form.h"

int main() {
    Form* form = nullptr;
    ISplitter* splitter = nullptr;

    splitter = new BinarySplitter();
    form = new Form(splitter);
    form->Click();

    splitter = new VideoSplitter();
    form = new Form(splitter);
    form->Click();

    return EXIT_SUCCESS;
}