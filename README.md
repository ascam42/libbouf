# Libbouf
A library on top of LibC that tracks allocations and more...

Summary
* [Get the LibBouf](#Get-the-LibBouf)
* [Builf the LibBouf and with the LibBouf](#Get-the-LibBouf-and-with-the-LibBouf)



## Get the LibBouf

	git clone https://github.com/encein42/libbouf

You also may want to add it as a submodule in your working git repository



## Build the LibBouf and with the LibBouf

Your repo shall be organised like this :

	. #Your working root
	├── libbouf
	│   ├── include
	│   │   └── #LibBouf's headers...
	│   ├── Makefile
	│   ├── README.md
	│   └── srcs
	│       └── #LibBouf's srcs...
	├── #Your Makefile
	├── #Your source files (where ever you want)
	└── include
	    └── #Your headers

*NOTE:* the `WORKING_ROOT/include` directory shall be included (`-Iinclude`) in your compilation. It will contain libbouf's headers (after libbouf compilation).

In your Makefile, add the following lines :

	LDFLAGS += -Llibbouf/
	LDLIBS += -lbouf
	...
	make -C libbouf/

Then, `make` your project.

*NOTE:* Don't forget to add `$(LDFLAGS)` and `$(LDLIBS)`, along with `-Iinclude`


