<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<CodeBlocks_project_file>
	<FileVersion major="1" minor="6" />
	<Project>
		<Option title="HWK6_pavlicpm" />
		<Option pch_mode="2" />
		<Option compiler="gcc" />
		<Build>
			<Target title="Debug">
				<Option output="bin/Debug/HWK6_pavlicpm" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Debug/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-g" />
				</Compiler>
			</Target>
			<Target title="Release">
				<Option output="bin/Release/HWK6_pavlicpm" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Release/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-O2" />
				</Compiler>
				<Linker>
					<Add option="-s" />
				</Linker>
			</Target>
		</Build>
		<Compiler>
			<Add option="-Wall" />
			<Add option="-fexceptions" />
		</Compiler>
		<Unit filename="Addition.cpp" />
		<Unit filename="Addition.h" />
		<Unit filename="ArithmeticExpression.cpp" />
		<Unit filename="ArithmeticExpression.h" />
		<Unit filename="Division.cpp" />
		<Unit filename="Division.h" />
		<Unit filename="Expression.cpp" />
		<Unit filename="Expression.h" />
		<Unit filename="Multiplication.cpp" />
		<Unit filename="Multiplication.h" />
		<Unit filename="Subtraction.cpp" />
		<Unit filename="Subtraction.h" />
		<Unit filename="main.cpp" />
		<Extensions>
			<code_completion />
			<envvars />
			<debugger />
			<lib_finder disable_auto="1" />
		</Extensions>
	</Project>
</CodeBlocks_project_file>
