#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
    if (!new_node || !*new_node)
    {
        fprintf(stderr, "Error: Unable to add to stack\n");
        exit(EXIT_FAILURE);
    }

    (*new_node)->next = head;
    if (head)
        head->prev = *new_node;
    head = *new_node;
}

/**
 * print_stack - Prints all elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;

    (void)line_number;

    if (!stack)
    {
        fprintf(stderr, "Error: Unable to print stack\n");
        exit(EXIT_FAILURE);
    }

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * pop_top - Removes the top element from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = *stack;
    *stack = tmp->next;
    if (*stack)
        (*stack)->prev = NULL;

    free(tmp);
}

/**
 * print_top - Prints the value of the top element in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
