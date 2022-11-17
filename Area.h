#pragma once
#include <DxLib.h>
int window_x, window_y, dx = 0;
//�v���O�������́u�ʒu�v�̃N���X
//�ʒu�ƃT�C�Y���E�B���h�E��Ōv�Z
bool mouse_in_area(int startX, int startY, int endX, int endY) {
	int mouseX = 0, mouseY = 0;
	GetMousePoint(&mouseX, &mouseY);
	return (mouseX >= startX && mouseX <= endX && mouseY >= startY && mouseY <= endY);
}
class WindowArea {
public:
	int startX, startY, endX, endY;
	WindowArea(float posX, float posY, float sizeX, float sizeY) {
		this->startX = (float)window_x * posX;
		this->startY = (float)window_y * posY;
		this->endX = this->startX + (float)window_x * sizeX;
		this->endY = this->startY + (float)window_y * sizeY;
	}
	// �}�E�X�̃N���b�N�ʒu����֐�
	bool mouse_in() {
		return mouse_in_area(this->startX, this->startY, this->endX, this->endY);
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

};
class WindowArea2 {
public:
	int startX, startY, endX, endY;
	WindowArea2(float posX, float posY, float sizeX, float sizeY) {
		this->startX = (float)window_y * posX;
		this->startY = (float)window_y * posY;
		this->endX = this->startX + (float)window_y * sizeX;
		this->endY = this->startY + (float)window_y * sizeY;
	}
	// �}�E�X�̃N���b�N�ʒu����֐�
	bool mouse_in() {
		return mouse_in_area(this->startX, this->startY, this->endX, this->endY);
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
};
//�ʒu�̓E�B���h�E��A�T�C�Y�͌Œ�
class ConstArea {
public:
	int startX, startY, endX, endY;
	ConstArea(float posX, float posY, int sizeX, int sizeY) {
		this->startX = window_x * posX - (sizeX / 2);
		this->startY = window_y * posY - (sizeY / 2);
		this->endX = this->startX + sizeX;
		this->endY = this->startY + sizeY;
	}
	// �}�E�X�̃N���b�N�ʒu����֐�
	bool mouse_in() {
		return mouse_in_area(this->startX, this->startY, this->endX, this->endY);
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
};
//�ʒu�̓E�B���h�E��A�T�C�Y�͌Œ�
class CircleArea {
public:
	int centerX, centerY, r;
	CircleArea(float posX, float posY, int size) {
		this->centerX = window_x * posX;
		this->centerY = window_y * posY;
		this->r = size;
	}
	// �}�E�X�̃N���b�N�ʒu����֐�
	bool mouse_in() {
		int mouseX = 0, mouseY = 0;
		GetMousePoint(&mouseX, &mouseY);
		return pow(mouseX - centerX, 2) + pow(mouseY - centerY, 2) <= pow(r,2);
	}
};