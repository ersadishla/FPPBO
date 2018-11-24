#pragma once
#include "wx\wx.h"
class ImageWindow : public wxWindow
{
public:
	ImageWindow(wxFrame *parent);
	~ImageWindow();
	void OnPaint(wxPaintEvent &event);
	void OnButtonClick(wxCommandEvent& event);
private:
	wxBitmap *potatoBitmap = nullptr;
	DECLARE_EVENT_TABLE()
	void LoadPotatoBitmap();
};
