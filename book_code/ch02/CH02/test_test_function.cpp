void test_function(char a, char b);

int main()
{
  char a, b;
  for (a = 'A'; a <= 'Z'; a++)
    for (b = 'A'; b <= 'Z'; b++)
      test_function(a, b);
}
