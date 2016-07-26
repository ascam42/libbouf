# Libbouf
## A library on top of LibC that tracks allocations and more...


## Get LibBouf

	git clone https://github.com/encein42/libbouf

You also may want to add it as a submodule in your working git repository


## Build LibBouf

Your repo shall be organised like this :

	. #Your working root
	├── libbouf
	│   ├── include
	│   │   └── #LibBouf's headers...
	│   ├── Makefile
	│   ├── README.md
	│   └── srcs
	│       └── #LibBouf's srcs...
	├── your_Makefile
	├── #your source files (where ever you want)
	└── include
	    └── #Your headers

**NOTE:** tht `WORKING_ROOT/include` directory shall be included (`-Iinclude`) in your compilation. It will contain libbouf's headers (after libbouf compilation)

In your Makefile, add the following lines :

	LDFLAGS += -Llibbouf/
	LDLIBS += -lbouf
	...
	make -C libbouf/

Then, `make` your project
	

