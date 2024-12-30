#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200)) {
        // Create a button
        wxButton* closeButton = new wxButton(this, wxID_EXIT, "Close");

        // Bind the button click event to the OnClose method
        closeButton->Bind(wxEVT_BUTTON, &MyFrame::OnClose, this);

        // Show the frame
        Show();
    }

private:
    void OnClose(wxCommandEvent& event) {
        Close(true); // Close the application
    }

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_EXIT, MyFrame::OnClose)
wxEND_EVENT_TABLE()

class MyApp : public wxApp {
public:
    bool OnInit() override {
        MyFrame* frame = new MyFrame("Hello, wxWidgets!");
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
