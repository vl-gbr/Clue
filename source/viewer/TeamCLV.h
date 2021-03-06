//Column list view header file


#ifndef _TEAMCLV_H_
#define _TEAMCLV_H_


//******************************************************************************************************
//**** PROJECT HEADER FILES AND CLASS NAME DECLARATIONS
//******************************************************************************************************
#ifndef _CLV_COLUMN_LIST_VIEW_H_
#include "ColumnListView.h"
#endif

//******************************************************************************************************
//**** ColumnListView CLASS DECLARATION
//******************************************************************************************************
class TeamCLV : public ColumnListView
{
	public:
		//Constructor and destructor
		TeamCLV (BRect,
						rgb_color,
						//Used to get back a pointer to the container
						BetterScrollView **,	//Used to get back a pointer to the container
												//view that will hold the ColumnListView, the
												//the CLVColumnLabelView, and the scrollbars.
												//If no scroll bars or border are asked for,
												//this will act like a plain BView container.
						const char * Name = NULL,
						uint32 ResizingMode = B_FOLLOW_LEFT | B_FOLLOW_TOP,
						uint32 flags = B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE,
						list_view_type Type = B_SINGLE_SELECTION_LIST,
						bool hierarchical = false,
						bool horizontal = true,					//Which scroll bars should I add, if any
						bool vertical = true,
						//bool scroll_view_corner = true,
						border_style border = B_NO_BORDER,		//What type of border to add, if any
						const BFont* LabelFont = be_plain_font);
		virtual			~TeamCLV (void);
		virtual bool	InitiateDrag (BPoint, int32, bool);
		virtual void	MouseDown (BPoint);
		virtual void	KeyDown (const char *, int32);
		virtual void	MessageReceived (BMessage *);
	private:
						TeamCLV (const TeamCLV &);
						TeamCLV & operator= (TeamCLV &);
	private:
		void			DoContextMenu (int32, BPoint, bool);
		void			CopyToClipboard (void);
	private:
		BPopUpMenu *	m_popupmenu;
};


#endif


