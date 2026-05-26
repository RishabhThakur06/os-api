#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void performOperation(char operation, int a, int b)
{
    int result;

    switch (operation)
    {
        case '+':
            result = a + b;
            printf("Result: %d\n", result);
            break;

        case '-':
            result = a - b;
            printf("Result: %d\n", result);
            break;

        case '*':
            result = a * b;
            printf("Result: %d\n", result);
            break;

        case '/':
            if (b != 0)
            {
                result = a / b;
                printf("Result: %d\n", result);
            }
            else
            {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            break;

        default:
            printf("Invalid operation\n");
            exit(EXIT_FAILURE);
    }
}

int main()
{
    char operation;
    int operand1, operand2;
    pid_t pid;
    int status;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    printf("Enter first number: ");
    scanf("%d", &operand1);

    printf("Enter second number: ");
    scanf("%d", &operand2);

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        performOperation(operation, operand1, operand2);
        exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Child process completed successfully\n");
        }
        else
        {
            printf("Child process terminated abnormally\n");
        }
    }

    return EXIT_SUCCESS;
}