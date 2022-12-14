#pragma once
#include <DxLib.h>
#include <math.h>
int window_x, window_y, dx = 0;
//プログラム内の「位置」のクラス
//位置とサイズをウィンドウ比で計算
class Area {
protected:
	int startX, startY, endX, endY;
	Area() {
		this->startX = this->startY = this->endX = this->endY = 0;
	}
public:
	Area(float posX, float posY, int sizeX, int sizeY) {
		this->startX = posX;
		this->startY = posY;
		this->endX = this->startX + sizeX;
		this->endY = this->startY + sizeY;
	}
	// マウスのクリック位置判定関数
	bool mouse_in() {
		int mouseX = 0, mouseY = 0;
		GetMousePoint(&mouseX, &mouseY);
		return mouseX >= this->startX && mouseX <= this->endX && mouseY >= this->startY && mouseY <= this->endY;
	}
	int DrawExtendGraph(int GrHandle) {
		return DxLib::DrawExtendGraph(this->startX, this->startY, this->endX, this->endY, GrHandle, true);
	}
	int DrawRotaGraph(double exRate, int GrHandle) {
		return DxLib::DrawRotaGraph((this->startX + this->endX) / 2, (this->startY + this->endY) / 2, exRate, 0, GrHandle, true);
	}
	int DrawBox(unsigned int color, int fillflg) {
		return DxLib::DrawBox(this->startX, this->startY, this->endX, this->endY, color, fillflg);
	}
	int DrawX(unsigned int color) {
		return DxLib::DrawLine(this->startX, this->startY, this->endX, this->endY, color) || DxLib::DrawLine(this->startX, this->endY, this->endX, this->startY, color);
	}
};
class WindowArea : public Area {
public:
	WindowArea(float posX, float posY, float sizeX, float sizeY) {
		this->startX = (float)window_x * posX;
		this->startY = (float)window_y * posY;
		this->endX = this->startX + (float)window_x * sizeX;
		this->endY = this->startY + (float)window_y * sizeY;
	}
};
class WindowArea2 : public Area {
public:
	WindowArea2(float posX, float posY, float sizeX, float sizeY) {
		this->startX = (float)window_y * posX;
		this->startY = (float)window_y * posY;
		this->endX = this->startX + (float)window_y * sizeX;
		this->endY = this->startY + (float)window_y * sizeY;
	}
};
//位置はウィンドウ比、サイズは固定
class ConstArea : public Area {
public:
	ConstArea(float posX, float posY, int sizeX, int sizeY) {
		this->startX = window_x * posX - (sizeX / 2);
		this->startY = window_y * posY - (sizeY / 2);
		this->endX = this->startX + sizeX;
		this->endY = this->startY + sizeY;
	}
};
//位置はウィンドウ比、サイズは固定
class CircleArea {
public:
	int centerX, centerY, r;
	CircleArea(float posX, float posY, int size) {
		this->centerX = window_x * posX;
		this->centerY = window_y * posY;
		this->r = size;
	}
	// マウスのクリック位置判定関数
	bool mouse_in() {
		int mouseX = 0, mouseY = 0;
		GetMousePoint(&mouseX, &mouseY);
		return pow(mouseX - centerX, 2) + pow(mouseY - centerY, 2) <= pow(r,2);
	}
};