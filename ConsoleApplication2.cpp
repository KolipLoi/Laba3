#include <iostream> 
#include <fstream> 
#include <string> 

struct Figure {
    std::string stroke;
    double x1;
    double y1;
    double x2;
    double y2;
};


struct Line : Figure {
    double stroke_width;
    Line(double new_x1, double new_y1, double new_x2, double new_y2, std::string new_stroke, double new_stroke_width) {
        x1 = new_x1;
        y1 = new_y1;
        y2 = new_y2;
        x2 = new_x2;
        stroke = new_stroke;
        stroke_width = new_stroke_width;
    }

};
std::ostream& operator <<(std::ostream& os, const Line& l) {
    return os << "<line x1=\"" << l.x1 << "\" y1=\"" << l.y1 << "\" x2=\"" << l.x2 << "\" y2=\"" << l.y2 << "\" stroke=\"" << l.stroke << "\" stroke-width=\"" << l.stroke_width << "\" />";
}

struct Poligon : Figure {
    double x3;
    double y3;
    double x4;
    double y4;
    std::string fill;
    Poligon(double new_x1, double new_y1, double new_x2, double new_y2, double new_x3, double new_y3, double new_x4, double new_y4, std::string new_fill, std::string new_stroke) {
        x1 = new_x1;
        y1 = new_y1;
        x2 = new_x2;
        y2 = new_y2;
        x3 = new_x3;
        y3 = new_y3;
        x4 = new_x4;
        y4 = new_y4;
        fill = new_fill;
        stroke = new_stroke;
    }
};
std::ostream& operator <<(std::ostream& os, const Poligon& p) {
    return os << "<polygon points=\"" << p.x1 << "," << p.y1 << " " << p.x2 << "," << p.y2 << " " << p.x3 << "," << p.y3 << " " << p.x4 << "," << p.y4 << "\" fill=\"" << p.fill << "\" stroke=\"" << p.stroke << "\" />";
}



int main() {
    std::ofstream svg("img.svg");
    Line line(140, 540, 240, 330, "#101c43", 60);
    Line line2(140, 620, 330, 230, "#2c65ce", 15);
    Poligon pol1(130, 640, 140, 650, 380, 230, 340, 210, "#fcd43f", "dashed");
    Poligon pol2(150, 632, 240, 690, 610, 190, 450, 100, "#090303", "dashed");
    Line line3(345, 605, 465, 445, "#385f2f", 70);
    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"800\"  style=\"background-color: #ffffff;\">";
    svg << line << line2 << pol1 << pol2 << line3;
    svg << "</svg>";
    svg.close();
    return 0;
}
