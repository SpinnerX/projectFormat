#include <formatCpp/formatCpp.h>
#include <formatCpp/containers.h>
#include <formatCpp/ffstream.h>
#include <formatCpp/ofstream.h>
#include <vector>

struct Point{
    Point(int _x, int _y) : x(_x), y(_y){}
    int x=0, y=0;

    friend std::ostream& operator<<(std::ostream& outs, const Point& rhs){
        outs << "(" << rhs.x << ", " << rhs.y << ")";
        return outs;
    }
};

int main(){
    // formatCpp::print("Current thread id: {}\n", formatCpp::streamed(std::this_thread::get_id()));
    Point point = Point(2, 3);
    formatCpp::print("Current Point: {}\n", formatCpp::streamed(point));

    formatCpp::print("Current Point2: {}\n", formatCpp::streamed(Point(30, 23)));

    std::vector<int> vec = {1, 2, 3, 4, 5};

    // formatCpp::print("{}\n", formatCpp::join(vec, "\n"));

    formatCpp::print("{}\n", vec);

    formatCpp::print("Current thread id: {}\n", formatCpp::streamed(std::this_thread::get_id()));
}