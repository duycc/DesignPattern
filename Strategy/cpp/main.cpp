
#include "context.h"

int main() {
    Context* ctx = new Context();
    std::vector<int> vec{10, 23, -1, 0, 300, 87, 28, 77, -32, 2};
    ctx->SetInput(vec);
    ctx->Print();

    ctx->SetSortStrategy(new BubbleSort());
    ctx->sort();

    ctx->SetSortStrategy(new SelectionSort());
    ctx->sort();

    ctx->SetSortStrategy(new InsertSort());
    ctx->sort();

    delete ctx;
    ctx = nullptr;

    return EXIT_SUCCESS;
}