#pragma once
#include <graphics.h>

class card {

public:
	void png();

	void draw_card();

	card();

	card(int in_num, int in_colour);

	void costume_print(int x, int y);

	int get_n();
	int get_c();

	void set_n(int n);
	void set_c(int c);

	~card();

private:
	int num; // card number
	int colour; // colour (r,g,b,y)
	graphics::Brush br; // card's brush
};
