# Cconsolef

## How to config terminal?
In another terminal
```sh
$ tty > /tmp/MyTerminal
```

## How does it work?
```c++
int main(int args, const char** kargs){
	consoleController* myTerm = consoleStart("MyTerminal");

	printf("Hello Dev!\n");
	consolef(myTerm, "Hello %s\n", "world");

	usleep(100000);
	delete myTerm;
	return 0;
}
```

## Building code.
In main terminal
```sh
$ make
```
## Outputs
#### main terminal
> Hello Dev!
#### second terminal
> Hello world
