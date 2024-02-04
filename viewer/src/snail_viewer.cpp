#include <snail/svg.hpp>

int main(int argc, char* argv[])
{
    Snail::Svg* svg = new Snail::Svg();
    svg->init(800, 600);
    svg->load("test.svg");
    svg->run();
    return 0;
}