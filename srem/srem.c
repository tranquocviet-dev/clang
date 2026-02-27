#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
  FILE *f = fopen("data.txt", "a");
  if (f == NULL)
    {
      printf("");
      printf("Error opening file");
    }
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char buffer[100];
  strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M", t);
  fprintf(f, "\n%s\n", buffer);
  
  char message[100];
  printf("enter the message:\n");
  scanf("%[^\n]", message);
  fprintf(f, "%s", message);
  fprintf(f, "\n");
  fclose(f);
  return 0;
}
