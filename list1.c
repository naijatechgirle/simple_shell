#include "shell.h"

/**
 * list_len - determines the length of a linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * list_to_strings - returns an array of strings from a list
 * @head: pointer to the first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t len = list_len(head);
	char **strs;
	char *str;
	size_t i;

	if (!head || !len)
		return (NULL);

	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(my_strlen(node->str) + 1);
		if (!str)
		{
			for (; i > 0; i--)
				free(strs[i - 1]);
			free(strs);
			return (NULL);
		}
		str = my_strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elements of a linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		my_puts(convert_number(h->num, 10, 0));
		my _putchar(':');
		my_putchar(' ');
		my_puts(h->str ? h->str : "(nil)");
		my_puts("\n");
		h = h->next;
		count++;
	}
	return (count);
}
/**
 * node_starts_with - returns a node whose string starts with a prefix
 * @node: pointer to the list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: matching node or NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to the list head
 * @node: pointer to the node
 *
 * Return: index of the node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (index);
		head = head->next;
		index++;
	}
	return (-1);
}
