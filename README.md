<h1>minitalk 💬</h1> <h2 align='right'>Final Grade 125/125 ✅ </h2>
The purpose of this project is to code a small data exchange program using UNIX signals.

<h2 align="center"> Description </h2>

Creates a communication program in the form of a client and a server.
- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
  - The server PID.
  - The string to send.
- The client must send the string passed as a parameter to the server. </br>
Once the string has been received, the server must print it.
- The server has to display the string pretty quickly.
- The communication between client and server has to be done only using UNIX signals.
- Only uses these two signals: SIGUSR1 and SIGUSR2.
- The server acknowledges every message received by sending back a signal to the
client.
- Supports Unicode characters!

<h2 align="center"> Server </h2>

<h3>main Function</h3>

This function sets up the server to receive signals and handle them using stoc.

```c

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		printf("ERROR, No arguments needed!\n");
		return (1);
	}
	ft_printf("PID : ");
	pid = getpid();
	ft_printf("%d\n", pid);
	act.sa_sigaction = stoc;
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return (0);
}

```

<h4>Parameters:</h4>

  - int argc: Number of command-line arguments.
  - char **argv: Array of command-line arguments.

<h4>Functionality:</h4>

  - Checks if the correct number of arguments is passed (no arguments needed).
  - Prints the server's PID to allow clients to send signals to it.
  - Configures struct sigaction to use stoc as the handler for SIGUSR1 and SIGUSR2.
  - Enters an infinite loop to keep the server running and handling signals.

<h3>stoc Function</h3>

This function serves as a signal handler to decode characters sent bit-by-bit using signals.

```c

void	stoc(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	word;

	(void)context;
	if (sig == SIGUSR1)
		word += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write (1, &word, 1);
		if (word == '\0')
		{
			kill(info->si_pid, SIGUSR2);
		}
		word = 0;
		bit = 0;
	}
}

```

<h4>Parameters:</h4>

  - int sig: The signal number received (SIGUSR1 or SIGUSR2).
  - siginfo_t *info: Additional information about the signal, including the PID of the sending process.
  - void *context: Context information (unused).

<h4>Functionality:</h4>

- Static Variables:
  - bit: Keeps track of the current bit position (0-7).
  - word: Accumulates the bits to form a character.
- When SIGUSR1 is received, the corresponding bit in word is set.
- bit is incremented to move to the next bit position.
- When 8 bits (1 byte) are accumulated:
  - The character is written to the standard output.
  - If the character is a null character ('\0'), it sends SIGUSR2 to the client's PID to acknowledge receipt.
  - Resets word and bit for the next character.

<h2 align="center"> Client </h2>

<h3>main Function</h3>

This function handles the client's main logic to send a message to the server.

```c
int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			ctos(pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR2, server_check);
		ctos(pid, '\n');
		ctos(pid, '\0');
	}
	else
	{
		ft_printf("ERROR, Arguments passed	problem\n");
		return (1);
	}
	return (0);
}
```
<h4>Parameters:</h4>

 - int argc: Number of command-line arguments.
 - char **argv: Array of command-line arguments.

<h4>Functionality:</h4>

 - Checks if the correct number of arguments is passed (server PID and message).
 - Converts the server PID from string to integer using ft_atoi.
 - Iterates through the message string, sending each character to the server using ctos.
 - Sets up a signal handler to receive acknowledgment from the server.
 - Sends a newline ('\n') and null character ('\0') to indicate the end of the message.

<h3>ctos Function</h3>

This function sends a character to the server bit-by-bit using signals.

```c
void	ctos(pid_t pid, char c)
{
	static int	bit;

	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
	bit = 0;
}
```
<h4>Parameters:</h4>

 - pid_t pid: The PID of the server process.
 - char c: The character to be sent.

<h4>Functionality:</h4>

  - Static Variable:
    - bit: Keeps track of the current bit position (0-7).
 - For each bit in the character:
    - Sends SIGUSR1 if the bit is 1.
    - Sends SIGUSR2 if the bit is 0.
    - Uses usleep to delay between signals, allowing the server to process each bit.
 - Resets bit for the next character.

<h3>Example Usage</h3>

- Compile using the Makefile:
  
```bash
make
```

- Start the server and copy the printed pid:
```bash
./server
```

- Open another terminal and run the client:
```bash
./client <pid> <string to send>
```

The server will receive the string sent by the client and print it.

<h2 align='center'>That's it</h2>



















