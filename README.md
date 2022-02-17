The project is based on x86 architecture because I've chosen to import the 32bit version of the GLFW library.

The project has structured by the MVVM paradigm. We have models, views, and view models. I created two views for the program (console and window). You can initialize whichever you like. The view can only talk to the ViewModel layer and have no idea what’s going on in the model layer. ViewModel is like a middleware that gets data from the model layer and transfers data to view. The model layer just contains data and cannot talk to other layers.

I’ve used the command pattern to execute specific commands like buy stuff or complete a job. For example, in the console application, if you press ‘I’ to see inventory, a command will execute to show the inventory, or if you press the ‘buy’ button in the window application, a command will execute to do purchasing operation.

I’ve used ImGui and OpenGl to create the window application. Although ImGui has lots of awesome features for UI, I’d tried to keep things as simple as possible.
