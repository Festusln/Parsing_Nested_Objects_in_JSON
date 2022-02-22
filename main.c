#include<stdio.h>
#include<string.h>
#include<json-c/json.h>

int main()
{
    char buffer[1024]; //location to what is in widget.json file
    FILE *fp = NULL;

    //object structs to hold parsed json
    struct json_object *parsed_json;
    struct json_object *parsed_json_window;
    struct json_object *parsed_json_image;
    struct json_object *parsed_json_text;

    
    //struct to hold individual document in the json file
    struct json_object *widget;

    struct json_object *debug;

    struct json_object *window;
        struct json_object *title;
        struct json_object *name;
        struct json_object *width;
        struct json_object *height;

    struct json_object *image;
        struct json_object *src;
        struct json_object *image_name;
        struct json_object *hOffset;
        struct json_object *vOffset;
        struct json_object *alignment;

    struct json_object *text;
        struct json_object *data;
        struct json_object *size;
        struct json_object *style;
        struct json_object *text_name;
        struct json_object *text_hOffset;
        struct json_object *text_vOffset;  
        struct json_object *text_alignment;
        struct json_object *onMouseUp;

    fp = fopen("widget.json", "r");     //opening json file in read nmode
    fread(buffer, 1024, 1, fp);         //reading content into buffer
    fclose(fp);                         //  closing the json file

    //Parsing the json file
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "widget", &widget);
    parsed_json = json_tokener_parse(json_object_get_string(widget));

    json_object_object_get_ex(parsed_json, "debug", &debug);
    printf("debug : %s\n", json_object_get_string(debug));

    //Getting objects in window object
    json_object_object_get_ex(parsed_json, "window", &window);
    parsed_json_window = json_tokener_parse(json_object_get_string(window));
    
    printf("\nList of objects in window object\n");
    json_object_object_get_ex(parsed_json_window, "title", &title);
    printf("title : %s\n", json_object_get_string(title));

    json_object_object_get_ex(parsed_json_window, "name", &name);
    printf("name : %s\n", json_object_get_string(name));

    json_object_object_get_ex(parsed_json_window, "width", &width);
    printf("width : %d\n", json_object_get_int(width));

    json_object_object_get_ex(parsed_json_window, "height", &height);
    printf("height : %d\n", json_object_get_int(height));

    //Getting objects in image object
    json_object_object_get_ex(parsed_json, "image", &image);
    parsed_json_image = json_tokener_parse(json_object_get_string(image));
   
    printf("\nList of objects in image object\n");
    json_object_object_get_ex(parsed_json_image, "src", &src);
    printf("src : %s\n", json_object_get_string(src));

    json_object_object_get_ex(parsed_json_image, "name", &text_name);
    printf("name : %s\n", json_object_get_string(text_name));

    json_object_object_get_ex(parsed_json_image, "hOffset", &hOffset);
    printf("hOffset : %d\n", json_object_get_int(hOffset));

    json_object_object_get_ex(parsed_json_image, "vOffset", &vOffset);
    printf("vOffset : %d\n", json_object_get_int(vOffset));

    json_object_object_get_ex(parsed_json_image, "alignment", &alignment);
    printf("alignment : %s\n", json_object_get_string(alignment));
    
    //Getting objects in text object
    json_object_object_get_ex(parsed_json, "text", &text);
    parsed_json_text = json_tokener_parse(json_object_get_string(text));
   
    printf("\nList of objects in text object\n");
    json_object_object_get_ex(parsed_json_text, "data", &data);
    printf("data : %s\n", json_object_get_string(data));

    json_object_object_get_ex(parsed_json_text, "size", &size);
    printf("size : %d\n", json_object_get_int(size));

    json_object_object_get_ex(parsed_json_text, "style", &style);
    printf("style : %s\n", json_object_get_string(style));

    json_object_object_get_ex(parsed_json_text, "hOffset", &text_hOffset);
    printf("hOffset : %d\n", json_object_get_int(vOffset));

    json_object_object_get_ex(parsed_json_text, "vOffset", &text_vOffset);
    printf("vOffset : %d\n", json_object_get_int(text_vOffset));

    json_object_object_get_ex(parsed_json_text, "alignment", &text_alignment);
    printf("alignment : %s\n", json_object_get_string(text_alignment));

    json_object_object_get_ex(parsed_json_text, "onMouseUp", &onMouseUp);
    printf("onMouseUp : %s\n", json_object_get_string(onMouseUp));    




    return 0;

}