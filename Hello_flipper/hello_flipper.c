#include <stdio.h>
// Flipper Universal Register : control application flow and dynamic linking between apps
#include <furi.h>
// Flipper's GUI
#include <gui/gui.h>

// Draws the GUI
static void draw(Canvas* canvas, void* ctx)
{
	UNUSED(ctx);
	canvas_clear(canvas);

	canvas_set_font(canvas, FontPrimary);
   	canvas_draw_str(canvas, 32, 13, "Hello Flipper");

	canvas_set_font(canvas, FontSecondary);
	canvas_draw_str(canvas, 15, 40, " press back to exit ");
	
	canvas_draw_line(canvas, 2, 23, 126, 23);
}

// Handler for user input
static void input(InputEvent* input_event, void* ctx)
{
	furi_assert(ctx);
	FuriMessageQueue* event_queue = ctx;
	furi_message_queue_put(event_queue, input_event, FuriWaitForever);
}

// Main function
int hello_flipper_main(void* p)
{
	UNUSED(p);
	
	// Variables storing events sent by the Flipper API
	InputEvent event;
	FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));
	
	// Setting the function meant to draw the GUI
	ViewPort* view_port = view_port_alloc();
	view_port_draw_callback_set(view_port, draw, NULL);
	
	// Setting the function meant to handle user inputs
	view_port_input_callback_set(view_port, input, event_queue);
	
	// Don't ask me what this does it's required to set the GUI
	Gui* gui = furi_record_open(RECORD_GUI);
	gui_add_view_port(gui, view_port, GuiLayerFullscreen);

	while(true)
	{
		// Checking for new events
		furi_check(furi_message_queue_get(event_queue, &event, FuriWaitForever) == FuriStatusOk);
		
		// If the event is that the user pressed the back key
		if (event.key == InputKeyBack)
		{
			break;
		}
	}

	// Freeing everything before exiting
	furi_message_queue_free(event_queue);
	gui_remove_view_port(gui, view_port);
	view_port_free(view_port);
	furi_record_close(RECORD_GUI);

	return 0;
}
