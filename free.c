#include "monty.h"

/**
 * free_arr - free allocated memory for array
 * @arr: string array
*/
void free_arr(char **arr) 
{
  if (arr)
  {
    if (arr[0])
	{
      free(arr[0]);
    }
  }
}