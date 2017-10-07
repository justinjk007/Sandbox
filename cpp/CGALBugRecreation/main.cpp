#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/algorithm.h>
#include <CGAL/bounding_box.h>
#include <iostream>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef K::FT FT;
typedef K::Point_2 Point;
typedef K::Segment_2 Segment;
typedef K::Iso_rectangle_2 Rect;
typedef CGAL::Polygon_2<K> Polygon_2;

void doIntersect(Segment, list<Segment>);

int main()
{
    // Define points
    Point pp0(0, 0);
    Point pp1(49.06, 0);
    Point pp2(24.53, 0);
    Point pp3(-8.02174, 0);
    Point pp4(49.06, 0);
    Point pp5(79.8021, 48.8048);
    Point pp6(24.53, 0);
    Point pp7(-8.02174, 0);
    Point pp8(79.8021, 48.8048);
    Point pp9(65.5682, 78.2666);
    Point pp10(24.53, 0);
    Point pp11(-8.02174, 0);
    Point pp12(65.5682, 78.2666);
    Point pp13(-8.02174, 78.1607);
    Point pp14(24.53, 0);
    Point pp15(-8.02174, 0);
    Point pp16(8.02174, 78.1607);
    Point pp17(0, 0);
    Point pp18(24.53, 0);
    Point pp19(-8.02174, 0);
    Point pp20(0, 0);
    Point pp21(49.06, 0);
    Point pp22(24.53, 0);
    Point pp23(306.677, 0);
    Point pp24(49.06, 0);
    Point pp25(79.8021, 48.8048);
    Point pp26(24.53, 0);
    Point pp27(306.677, 0);
    Point pp28(0, 0);
    Point pp29(49.06, 0);
    Point pp30(24.53, 0);
    Point pp31(24.53, 254.187);
    Point pp32(49.06, 0);
    Point pp33(79.8021, 48.8048);
    Point pp34(24.53, 0);
    Point pp35(24.53, 254.187);
    Point pp36(79.8021, 48.8048);
    Point pp37(65.5682, 78.2666);
    Point pp38(24.53, 0);
    Point pp39(24.53, 254.187);
    Point pp40(65.5682, 78.2666);
    Point pp41(-8.02174, 78.1607);
    Point pp42(24.53, 0);
    Point pp43(24.53, 254.187);
    Point pp44(0, 0);
    Point pp45(49.06, 0);
    Point pp46(24.53, 0);
    Point pp47(24.53, -78.1607);
    Point pp48(49.06, 0);
    Point pp49(79.8021, 48.8048);
    Point pp50(24.53, 0);
    Point pp51(24.53, -78.1607);
    Point pp52(79.8021, 48.8048);
    Point pp53(65.5682, 78.2666);
    Point pp54(24.53, 0);
    Point pp55(24.53, -78.1607);
    Point pp56(65.5682, 78.2666);
    Point pp57(-8.02174, 78.1607);
    Point pp58(24.53, 0);
    Point pp59(24.53, -78.1607);
    Point pp60(8.02174, 78.1607);
    Point pp61(0, 0);
    Point pp62(24.53, 0);
    Point pp63(24.53, -78.1607);
    Point pp64(65.5682, 78.2666);
    Point pp65(79.8021, 48.8048);
    Point pp66(24.53, 0);
    Point pp67(24.53, -78.1607);
    Point pp68(79.8021, 48.8048);
    Point pp69(153.392, 48.9107);
    Point pp70(24.53, 0);
    Point pp71(24.53, -78.1607);
    Point pp72(153.392, 48.9107);
    Point pp73(145.263, 127.16);
    Point pp74(24.53, 0);
    Point pp75(24.53, -78.1607);
    Point pp76(145.263, 127.16);
    Point pp77(96.2031, 127.027);
    Point pp78(24.53, 0);
    Point pp79(24.53, -78.1607);
    Point pp80(96.2031, 127.027);
    Point pp81(65.5682, 78.2666);
    Point pp82(24.53, 0);
    Point pp83(24.53, -78.1607);
    Point pp84(57.0817, -78.1607);
    Point pp85(106.142, -78.1607);
    Point pp86(24.53, 0);
    Point pp87(24.53, -78.1607);
    Point pp88(106.142, -78.1607);
    Point pp89(136.884, -29.3559);
    Point pp90(24.53, 0);
    Point pp91(24.53, -78.1607);
    Point pp92(136.884, -29.3559);
    Point pp93(122.65, 0.105903);
    Point pp94(24.53, 0);
    Point pp95(24.53, -78.1607);
    Point pp96(122.65, 0.105903);
    Point pp97(49.06, 0);
    Point pp98(24.53, 0);
    Point pp99(24.53, -78.1607);
    Point pp100(49.06, 0);
    Point pp101(57.0817, -78.1607);
    Point pp102(24.53, 0);
    Point pp103(24.53, -78.1607);
    Point pp104(122.65, 0.105903);
    Point pp105(136.884, -29.3559);
    Point pp106(24.53, 0);
    Point pp107(24.53, -78.1607);
    Point pp108(136.884, -29.3559);
    Point pp109(210.474, -29.25);
    Point pp110(24.53, 0);
    Point pp111(24.53, -78.1607);
    Point pp112(210.474, -29.25);
    Point pp113(202.345, 48.9989);
    Point pp114(24.53, 0);
    Point pp115(24.53, -78.1607);
    Point pp116(202.345, 48.9989);
    Point pp117(153.285, 48.8663);
    Point pp118(24.53, 0);
    Point pp119(24.53, -78.1607);
    Point pp120(153.285, 48.8663);
    Point pp121(122.65, 0.105903);
    Point pp122(24.53, 0);
    Point pp123(24.53, -78.1607);
    Point pp124(96.2031, 127.027);
    Point pp125(145.263, 127.027);
    Point pp126(24.53, 0);
    Point pp127(24.53, -78.1607);
    Point pp128(145.263, 127.027);
    Point pp129(176.005, 175.832);
    Point pp130(24.53, 0);
    Point pp131(24.53, -78.1607);
    Point pp132(176.005, 175.832);
    Point pp133(161.771, 205.294);
    Point pp134(24.53, 0);
    Point pp135(24.53, -78.1607);
    Point pp136(161.771, 205.294);
    Point pp137(88.1814, 205.188);
    Point pp138(24.53, 0);
    Point pp139(24.53, -78.1607);
    Point pp140(88.1814, 205.188);
    Point pp141(96.2031, 127.027);
    Point pp142(24.53, 0);
    Point pp143(24.53, -78.1607);
    Point pp144(161.771, 205.294);
    Point pp145(176.005, 175.832);
    Point pp146(24.53, 0);
    Point pp147(24.53, -78.1607);
    Point pp148(176.005, 175.832);
    Point pp149(249.595, 175.938);
    Point pp150(24.53, 0);
    Point pp151(24.53, -78.1607);
    Point pp152(249.595, 175.938);
    Point pp153(241.466, 254.187);
    Point pp154(24.53, 0);
    Point pp155(24.53, -78.1607);
    Point pp156(241.466, 254.187);
    Point pp157(192.406, 254.054);
    Point pp158(24.53, 0);
    Point pp159(24.53, -78.1607);
    Point pp160(192.406, 254.054);
    Point pp161(161.771, 205.294);
    Point pp162(24.53, 0);
    Point pp163(24.53, -78.1607);
    Point pp164(153.285, 48.8663);
    Point pp165(202.345, 48.8663);
    Point pp166(24.53, 0);
    Point pp167(24.53, -78.1607);
    Point pp168(202.345, 48.8663);
    Point pp169(233.087, 97.6711);
    Point pp170(24.53, 0);
    Point pp171(24.53, -78.1607);
    Point pp172(233.087, 97.6711);
    Point pp173(218.853, 127.133);
    Point pp174(24.53, 0);
    Point pp175(24.53, -78.1607);
    Point pp176(218.853, 127.133);
    Point pp177(145.263, 127.027);
    Point pp178(24.53, 0);
    Point pp179(24.53, -78.1607);
    Point pp180(145.263, 127.027);
    Point pp181(153.285, 48.8663);
    Point pp182(24.53, 0);
    Point pp183(24.53, -78.1607);
    Point pp184(218.853, 127.133);
    Point pp185(233.087, 97.6711);
    Point pp186(24.53, 0);
    Point pp187(24.53, -78.1607);
    Point pp188(233.087, 97.6711);
    Point pp189(306.677, 97.777);
    Point pp190(24.53, 0);
    Point pp191(24.53, -78.1607);
    Point pp192(306.677, 97.777);
    Point pp193(298.548, 176.026);
    Point pp194(24.53, 0);
    Point pp195(24.53, -78.1607);
    Point pp196(298.548, 176.026);
    Point pp197(249.488, 175.893);
    Point pp198(24.53, 0);
    Point pp199(24.53, -78.1607);
    Point pp200(249.488, 175.893);
    Point pp201(218.853, 127.133);
    Point pp202(24.53, 0);
    Point pp203(24.53, -78.1607);
    Point pp204(0, 0);
    Point pp205(49.06, 0);
    Point pp206(64.431, 24.4024);
    Point pp207(-8.02174, 24.4024);
    Point pp208(49.06, 0);
    Point pp209(79.8021, 48.8048);
    Point pp210(64.431, 24.4024);
    Point pp211(-8.02174, 24.4024);
    Point pp212(79.8021, 48.8048);
    Point pp213(65.5682, 78.2666);
    Point pp214(64.431, 24.4024);
    Point pp215(-8.02174, 24.4024);
    Point pp216(65.5682, 78.2666);
    Point pp217(-8.02174, 78.1607);
    Point pp218(64.431, 24.4024);
    Point pp219(-8.02174, 24.4024);
    Point pp220(8.02174, 78.1607);
    Point pp221(0, 0);
    Point pp222(64.431, 24.4024);
    Point pp223(-8.02174, 24.4024);
    Point pp224(0, 0);
    Point pp225(49.06, 0);
    Point pp226(64.431, 24.4024);
    Point pp227(306.677, 24.4024);
    Point pp228(49.06, 0);
    Point pp229(79.8021, 48.8048);
    Point pp230(64.431, 24.4024);
    Point pp231(306.677, 24.4024);
    Point pp232(79.8021, 48.8048);
    Point pp233(65.5682, 78.2666);
    Point pp234(64.431, 24.4024);
    Point pp235(306.677, 24.4024);
    Point pp236(65.5682, 78.2666);
    Point pp237(-8.02174, 78.1607);
    Point pp238(64.431, 24.4024);
    Point pp239(306.677, 24.4024);
    Point pp240(8.02174, 78.1607);
    Point pp241(0, 0);
    Point pp242(64.431, 24.4024);
    Point pp243(306.677, 24.4024);
    Point pp244(65.5682, 78.2666);
    Point pp245(79.8021, 48.8048);
    Point pp246(64.431, 24.4024);
    Point pp247(306.677, 24.4024);
    Point pp248(79.8021, 48.8048);
    Point pp249(153.392, 48.9107);
    Point pp250(64.431, 24.4024);
    Point pp251(306.677, 24.4024);
    Point pp252(153.392, 48.9107);
    Point pp253(145.263, 127.16);
    Point pp254(64.431, 24.4024);
    Point pp255(306.677, 24.4024);
    Point pp256(145.263, 127.16);
    Point pp257(96.2031, 127.027);
    Point pp258(64.431, 24.4024);
    Point pp259(306.677, 24.4024);
    Point pp260(96.2031, 127.027);
    Point pp261(65.5682, 78.2666);
    Point pp262(64.431, 24.4024);
    Point pp263(306.677, 24.4024);
    Point pp264(57.0817, -78.1607);
    Point pp265(106.142, -78.1607);
    Point pp266(64.431, 24.4024);
    Point pp267(306.677, 24.4024);
    Point pp268(106.142, -78.1607);
    Point pp269(136.884, -29.3559);
    Point pp270(64.431, 24.4024);
    Point pp271(306.677, 24.4024);
    Point pp272(136.884, -29.3559);
    Point pp273(122.65, 0.105903);
    Point pp274(64.431, 24.4024);
    Point pp275(306.677, 24.4024);
    Point pp276(122.65, 0.105903);
    Point pp277(49.06, 0);
    Point pp278(64.431, 24.4024);
    Point pp279(306.677, 24.4024);
    Point pp280(49.06, 0);
    Point pp281(57.0817, -78.1607);
    Point pp282(64.431, 24.4024);
    Point pp283(306.677, 24.4024);
    Point pp284(122.65, 0.105903);
    Point pp285(136.884, -29.3559);
    Point pp286(64.431, 24.4024);
    Point pp287(306.677, 24.4024);
    Point pp288(136.884, -29.3559);
    Point pp289(210.474, -29.25);
    Point pp290(64.431, 24.4024);
    Point pp291(306.677, 24.4024);
    Point pp292(210.474, -29.25);
    Point pp293(202.345, 48.9989);
    Point pp294(64.431, 24.4024);
    Point pp295(306.677, 24.4024);
    Point pp296(0, 0);
    Point pp297(49.06, 0);
    Point pp298(64.431, 24.4024);
    Point pp299(64.431, 254.187);
    Point pp300(49.06, 0);
    Point pp301(79.8021, 48.8048);
    Point pp302(64.431, 24.4024);
    Point pp303(64.431, 254.187);
    Point pp304(79.8021, 48.8048);
    Point pp305(65.5682, 78.2666);
    Point pp306(64.431, 24.4024);
    Point pp307(64.431, 254.187);
    Point pp308(65.5682, 78.2666);
    Point pp309(-8.02174, 78.1607);
    Point pp310(64.431, 24.4024);
    Point pp311(64.431, 254.187);
    Point pp312(0, 0);
    Point pp313(49.06, 0);
    Point pp314(64.431, 24.4024);
    Point pp315(64.431, -78.1607);
    Point pp316(49.06, 0);
    Point pp317(79.8021, 48.8048);
    Point pp318(64.431, 24.4024);
    Point pp319(64.431, -78.1607);
    Point pp320(79.8021, 48.8048);
    Point pp321(65.5682, 78.2666);
    Point pp322(64.431, 24.4024);
    Point pp323(64.431, -78.1607);
    Point pp324(65.5682, 78.2666);
    Point pp325(-8.02174, 78.1607);
    Point pp326(64.431, 24.4024);
    Point pp327(64.431, -78.1607);
    Point pp328(8.02174, 78.1607);
    Point pp329(0, 0);
    Point pp330(64.431, 24.4024);
    Point pp331(64.431, -78.1607);
    Point pp332(65.5682, 78.2666);
    Point pp333(79.8021, 48.8048);
    Point pp334(64.431, 24.4024);
    Point pp335(64.431, -78.1607);
    Point pp336(79.8021, 48.8048);
    Point pp337(153.392, 48.9107);
    Point pp338(64.431, 24.4024);
    Point pp339(64.431, -78.1607);
    Point pp340(153.392, 48.9107);
    Point pp341(145.263, 127.16);
    Point pp342(64.431, 24.4024);
    Point pp343(64.431, -78.1607);
    Point pp344(145.263, 127.16);
    Point pp345(96.2031, 127.027);
    Point pp346(64.431, 24.4024);
    Point pp347(64.431, -78.1607);
    Point pp348(96.2031, 127.027);
    Point pp349(65.5682, 78.2666);
    Point pp350(64.431, 24.4024);
    Point pp351(64.431, -78.1607);
    Point pp352(57.0817, -78.1607);
    Point pp353(106.142, -78.1607);
    Point pp354(64.431, 24.4024);
    Point pp355(64.431, -78.1607);
    Point pp356(0, 0);
    Point pp357(49.06, 0);
    Point pp358(72.6851, 63.5357);
    Point pp359(-8.02174, 63.5357);
    Point pp360(49.06, 0);
    Point pp361(79.8021, 48.8048);
    Point pp362(72.6851, 63.5357);
    Point pp363(-8.02174, 63.5357);
    Point pp364(79.8021, 48.8048);
    Point pp365(65.5682, 78.2666);
    Point pp366(72.6851, 63.5357);
    Point pp367(-8.02174, 63.5357);
    Point pp368(65.5682, 78.2666);
    Point pp369(-8.02174, 78.1607);
    Point pp370(72.6851, 63.5357);
    Point pp371(-8.02174, 63.5357);
    Point pp372(8.02174, 78.1607);
    Point pp373(0, 0);
    Point pp374(72.6851, 63.5357);
    Point pp375(-8.02174, 63.5357);
    Point pp376(0, 0);
    Point pp377(49.06, 0);
    Point pp378(72.6851, 63.5357);
    Point pp379(306.677, 63.5357);
    Point pp380(49.06, 0);
    Point pp381(79.8021, 48.8048);
    Point pp382(72.6851, 63.5357);
    Point pp383(306.677, 63.5357);
    Point pp384(79.8021, 48.8048);
    Point pp385(65.5682, 78.2666);
    Point pp386(72.6851, 63.5357);
    Point pp387(306.677, 63.5357);
    Point pp388(65.5682, 78.2666);
    Point pp389(-8.02174, 78.1607);
    Point pp390(72.6851, 63.5357);
    Point pp391(306.677, 63.5357);
    Point pp392(8.02174, 78.1607);
    Point pp393(0, 0);
    Point pp394(72.6851, 63.5357);
    Point pp395(306.677, 63.5357);
    Point pp396(65.5682, 78.2666);
    Point pp397(79.8021, 48.8048);
    Point pp398(72.6851, 63.5357);
    Point pp399(306.677, 63.5357);
    std::list<Point> my_points = {
        pp0,   pp1,   pp2,   pp3,   pp4,   pp5,   pp6,   pp7,   pp8,   pp9,   pp10,  pp11,  pp12,
        pp13,  pp14,  pp15,  pp16,  pp17,  pp18,  pp19,  pp20,  pp21,  pp22,  pp23,  pp24,  pp25,
        pp26,  pp27,  pp28,  pp29,  pp30,  pp31,  pp32,  pp33,  pp34,  pp35,  pp36,  pp37,  pp38,
        pp39,  pp40,  pp41,  pp42,  pp43,  pp44,  pp45,  pp46,  pp47,  pp48,  pp49,  pp50,  pp51,
        pp52,  pp53,  pp54,  pp55,  pp56,  pp57,  pp58,  pp59,  pp60,  pp61,  pp62,  pp63,  pp64,
        pp65,  pp66,  pp67,  pp68,  pp69,  pp70,  pp71,  pp72,  pp73,  pp74,  pp75,  pp76,  pp77,
        pp78,  pp79,  pp80,  pp81,  pp82,  pp83,  pp84,  pp85,  pp86,  pp87,  pp88,  pp89,  pp90,
        pp91,  pp92,  pp93,  pp94,  pp95,  pp96,  pp97,  pp98,  pp99,  pp100, pp101, pp102, pp103,
        pp104, pp105, pp106, pp107, pp108, pp109, pp110, pp111, pp112, pp113, pp114, pp115, pp116,
        pp117, pp118, pp119, pp120, pp121, pp122, pp123, pp124, pp125, pp126, pp127, pp128, pp129,
        pp130, pp131, pp132, pp133, pp134, pp135, pp136, pp137, pp138, pp139, pp140, pp141, pp142,
        pp143, pp144, pp145, pp146, pp147, pp148, pp149, pp150, pp151, pp152, pp153, pp154, pp155,
        pp156, pp157, pp158, pp159, pp160, pp161, pp162, pp163, pp164, pp165, pp166, pp167, pp168,
        pp169, pp170, pp171, pp172, pp173, pp174, pp175, pp176, pp177, pp178, pp179, pp180, pp181,
        pp182, pp183, pp184, pp185, pp186, pp187, pp188, pp189, pp190, pp191, pp192, pp193, pp194,
        pp195, pp196, pp197, pp198, pp199, pp200, pp201, pp202, pp203, pp204, pp205, pp206, pp207,
        pp208, pp209, pp210, pp211, pp212, pp213, pp214, pp215, pp216, pp217, pp218, pp219, pp220,
        pp221, pp222, pp223, pp224, pp225, pp226, pp227, pp228, pp229, pp230, pp231, pp232, pp233,
        pp234, pp235, pp236, pp237, pp238, pp239, pp240, pp241, pp242, pp243, pp244, pp245, pp246,
        pp247, pp248, pp249, pp250, pp251, pp252, pp253, pp254, pp255, pp256, pp257, pp258, pp259,
        pp260, pp261, pp262, pp263, pp264, pp265, pp266, pp267, pp268, pp269, pp270, pp271, pp272,
        pp273, pp274, pp275, pp276, pp277, pp278, pp279, pp280, pp281, pp282, pp283, pp284, pp285,
        pp286, pp287, pp288, pp289, pp290, pp291, pp292, pp293, pp294, pp295, pp296, pp297, pp298,
        pp299, pp300, pp301, pp302, pp303, pp304, pp305, pp306, pp307, pp308, pp309, pp310, pp311,
        pp312, pp313, pp314, pp315, pp316, pp317, pp318, pp319, pp320, pp321, pp322, pp323, pp324,
        pp325, pp326, pp327, pp328, pp329, pp330, pp331, pp332, pp333, pp334, pp335, pp336, pp337,
        pp338, pp339, pp340, pp341, pp342, pp343, pp344, pp345, pp346, pp347, pp348, pp349, pp350,
        pp351, pp352, pp353, pp354, pp355, pp356, pp357, pp358, pp359, pp360, pp361, pp362, pp363,
        pp364, pp365, pp366, pp367, pp368, pp369, pp370, pp371, pp372, pp373, pp374, pp375, pp376,
        pp377, pp378, pp379, pp380, pp381, pp382, pp383, pp384, pp385, pp386, pp387, pp388, pp389,
        pp390, pp391, pp392, pp393, pp394, pp395, pp396, pp397, pp398, pp399};
    std::list<Segment> my_lines;
    cout << "Size of the list is " << my_points.size() << endl;
    while (!my_points.empty()) {
        Point p1 = my_points.front();
	my_points.pop_front();
        Point p2 = my_points.front();
	my_points.pop_front();

        Segment seg(p1, p2);
        my_lines.push_back(seg);
    }
    doIntersect(my_lines.front(), my_lines);
    return 0;
}

void doIntersect(Segment line, list<Segment> lines)
{
    /**
     * Check if the passed line segments intersects with any of the
     * lines inside the given list of lines.
     */
    for (auto& current : lines) {
        cout << "Segments just tested :" << current << " " << line << endl;
        if (CGAL::do_intersect(line, current))
	    cout << "They intersect\n";
	else
	    cout << "They don\'t intersect\n";
    }
}
