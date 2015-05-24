# moves objects to scan format

import bpy

selection = bpy.context.selected_objects

for obj in selection:
    name = obj.data.name
    if (name.find(".") == -1):
        continue
    elements = name.split(".")
    if (len(elements) != 2):
        continue
    number = int(elements[1]) - 281
    obj.location = (number % 18, int(number / 18), 0)