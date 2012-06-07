
#include "mrcore.h"
#include "mainWindow.h"
#include <wx/wx.h>
#include <wx/menu.h>

class Apolo : public wxApp
{
public:
	virtual bool OnInit();
	MainWindow* apoloMainWin;
};

IMPLEMENT_APP(Apolo);


bool Apolo::OnInit()
{
	mrcoreInit();
	apoloMainWin = new MainWindow((wxFrame *) NULL, wxID_ANY, wxT("APOLO"), wxDefaultPosition, wxSize(800,600), wxDEFAULT_FRAME_STYLE | wxHSCROLL | wxVSCROLL);

	//make a menu
	wxMenu *filemenu = new wxMenu;
	wxMenuItem *item1 = new wxMenuItem(filemenu, ID_NEW, wxT("New world"),wxT("Create a new world"));
	item1->SetBitmap(new_xpm);
	filemenu->Append(item1);
	wxMenuItem *item2 = new wxMenuItem(filemenu,ID_LOADWORLD, wxT("Load world"), wxT("Load a file of world"));
	item2->SetBitmap(loadWorld_xpm);
	filemenu->Append(item2);
	filemenu->AppendSeparator();
	filemenu->AppendCheckItem(ID_VIS_TREE, wxT("Unvisible tree"));
	if(apoloMainWin->getTreeVisible()==true)filemenu->Check(ID_VIS_TREE,false);
	filemenu->AppendSeparator();
	filemenu->Append(wxID_EXIT, wxT("E&xit"), wxT("Quit the program"));
	
	wxMenu *filemenu2 = new wxMenu;
	filemenu2->Append(wxID_ABOUT, wxT("&About..."), wxT("Information program"));

	wxMenuBar *menubar = new wxMenuBar;
	menubar->Append(filemenu, wxT("&File"));
	menubar->Append(filemenu2, wxT("About"));

	apoloMainWin->SetMenuBar(menubar);
	apoloMainWin->Show(true);
	SetTopWindow(apoloMainWin);
	return true;
}