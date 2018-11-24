#include "ImageWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
BEGIN_EVENT_TABLE(ImageWindow, wxWindow)
EVT_PAINT(ImageWindow::OnPaint)
EVT_BUTTON(wxID_ANY, ImageWindow::OnButtonClick)
END_EVENT_TABLE()
ImageWindow::ImageWindow(wxFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	//wxPanel *panel = new wxPanel(this, wxID_ANY);
	wxButton* button = new wxButton(this, wxID_ANY, wxT("startGame!"),
		wxPoint(770, 800), wxDefaultSize);
	this->SetBackgroundColour(wxColour(*wxWHITE));
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->LoadPotatoBitmap();
}
ImageWindow::~ImageWindow()
{
	delete potatoBitmap;
}
void ImageWindow::LoadPotatoBitmap()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() +
		wxT("\\gambar.jpg");
	wxMessageOutputDebug().Printf("Relative path of image is at %s",
		fileLocation);
	//wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	//jika menggunakan absolute path
	//sesuaikan path dimana lokasi file potato.jpg berada
	wxImage image(wxT("C:\\Users\\Phiton\\Pictures\\Feedback\\gambar.jpg"),
		wxBITMAP_TYPE_JPEG);
	potatoBitmap = new wxBitmap(image);
}

void ImageWindow::OnButtonClick(wxCommandEvent& event)
{
	wxMessageBox(wxT("Event klik terjadi pada tombol"));
}
void ImageWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (potatoBitmap != nullptr)
	{
		pdc.DrawBitmap(*potatoBitmap, wxPoint(150, 100), true);
	}
}
