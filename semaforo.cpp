#include <gtk-3.0/gtk/gtk.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
#include <array>
#include <gtkmm-3.0/gtkmm.h>

class Signals {
    private:
        std::string black = "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";
        std::string red = "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";
        std::string yellow = "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";
        std::string green = "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";

    public:
        void base64_to_img(std::string temp_file_name, std::string base64_image) {
            std::ofstream image_file(temp_file_name, std::ios::out | std::ios::binary);
            image_file << Glib::Base64::decode(base64_image);
            image_file.close();
        }

        Signals() {
            base64_to_img("black.png", this->black);
            base64_to_img("red.png", this->red);
            base64_to_img("yellow.png", this->yellow);
            base64_to_img("green.png", this->green);
        }

        void delete_temp() {
            std::remove("black.png");
            std::remove("red.png");
            std::remove("yellow.png");
            std::remove("green.png");
        }
};

Signals signals;

void on_window_close() {
    signals.delete_temp();
    gtk_main_quit();
}

int flashing_lights = 1;

GtkImage* img1 = nullptr;
GtkImage* img2 = nullptr;
GtkImage* img3 = nullptr;

void callback_start() {
    switch (flashing_lights) {
        case 0:
            gtk_image_set_from_file(img1, "red.png");
            gtk_image_set_from_file(img2, "black.png");
            gtk_image_set_from_file(img3, "black.png");
            flashing_lights++;
            break;
        case 1:
            gtk_image_set_from_file(img1, "black.png");
            gtk_image_set_from_file(img2, "yellow.png");
            gtk_image_set_from_file(img3, "black.png");
            flashing_lights++;
            break;
        case 2:
            gtk_image_set_from_file(img1, "black.png");
            gtk_image_set_from_file(img2, "black.png");
            gtk_image_set_from_file(img3, "green.png");
            flashing_lights++;
            break;
        default:
            flashing_lights = 0;
            gtk_image_set_from_file(img1, "red.png");
            gtk_image_set_from_file(img2, "black.png");
            gtk_image_set_from_file(img3, "black.png");
            flashing_lights++;
            break;
    }

}

int timer_delay = 5;

int timer_callback(gpointer data) {
    callback_start();

    g_timeout_add_seconds(timer_delay, timer_callback, NULL);

    return G_SOURCE_REMOVE;
}

void on_window_destroy() {
    signals.delete_temp();
    Gtk::Main::quit();
}

int main(int argc, char* argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;

    gtk_init(&argc, &argv);


    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "semaforo.glade", NULL); 

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    gtk_window_set_title(GTK_WINDOW(window), "Semáforo [KARBOX]");

    img1 = GTK_IMAGE(gtk_builder_get_object(builder, "img1"));
    img2 = GTK_IMAGE(gtk_builder_get_object(builder, "img2"));
    img3 = GTK_IMAGE(gtk_builder_get_object(builder, "img3"));

    gtk_image_set_from_file(img1, "red.png");

    g_timeout_add_seconds(timer_delay, timer_callback, NULL);

    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}