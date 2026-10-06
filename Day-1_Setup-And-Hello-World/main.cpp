#include "Windows.h"

#include "lvgl/lvgl.h"


int main(int argc, char** argv) 
{
    // 1. Initialize the internal LVGL data management engine
    lv_init();

    // 2. Spawn a native desktop window simulator (Resolution: 800*480)

    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = false;

    lv_display_t* display = lv_windows_create_display(
                                    L"Hello World",
                                    800,
                                    480,
                                    zoom_level,
                                    allow_dpi_override,
                                    simulator_mode);

    if (!display)
    {
        return -1;
    }

    // 3. Creating a label with text HelloWorld! and applying center alignment respective to parent.

    lv_obj_t* lbl = lv_label_create(lv_screen_active());
    lv_label_set_text(lbl, "Hello World!");
    lv_obj_align_to(lbl, NULL, LV_ALIGN_CENTER, 0, 0);


    // 4. Infinite execution loop updating the rendering canvas engine
    while (1) {
        // Run LVGL internal task processing (renders layout, checks for mouse touches)
        uint32_t time_till_next = lv_timer_handler();

        // Dynamic power saving: pause the CPU thread for exactly as long as LVGL needs
        Sleep(time_till_next);
    }

    return 0;
}