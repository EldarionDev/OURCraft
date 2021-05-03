<h1> BUILDING </h1> <br>
	<h2> On Linux </h2> <br>
		Prerequisites: <br> 
			- Libraries and their Development headers: GLEW, GLFW  <br>
			- Paste the stb_image.h from the stb project into your default include folder(usually /usr/include) <br>
		Building: <br>
		cd into the project directory, install make and execute it within the folder. This will build you an executable <br>
	<h2> On Windows </h2> <br>
		Prerequisites: <br>
			- Create a folder named dlls another one named includes another one named libraries inside the project folder <br>
			- Paste the glew32.dll and glfw3.dll into the dlls/ folder. <br>
			- Paste the GLEW, GLFW, glm includes and the stb_image.h inside the includes/ folder. <br>
			- Paste the glew32.lib and libglfw3.a inside the libraries/ folder. <br>
		Building: <br>
			- Build the project with CMake. The DLLs will automatically be places into the directory of the generated executable
