#pragma once
#include "pch.h"
class Keyboard
{
public:
	static std::shared_ptr<Keyboard> GetInstance();
	void SetPressed(UINT key);
	void SetHeld(UINT key);
	void SetReleased(UINT key);
	UINT GetPressed(UINT key) const { return pressed; }
	UINT GetHeld(UINT key) const { return held; }
	UINT GetReleased(UINT key) const { return released; }
private:
	static std::shared_ptr<Keyboard> instance;
	UINT pressed = 0;
	UINT held = 0;
	UINT released = 0;
};

