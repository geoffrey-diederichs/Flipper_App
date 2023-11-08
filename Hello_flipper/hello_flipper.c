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
   	canvas_draw_str(canvas, 32, 13, "My First App");

	canvas_set_font(canvas, FontSecondary);
	canvas_draw_str(canvas, 15, 40, " press back to exit FAP");
	
	canvas_draw_line(canvas, 2, 23, 126, 23);
}

// Handler for user input
static void input(InputEvent* input_event, void* ctx)
{
	furi_assert(ctx);
	FuriMessageQueue* event_queue = ctx;
	furi_message_queue_put(event_queue, input_event, FuriWaitForever);
}

int hello_flipper_main(void* p)
{
	UNUSED(p);

}
