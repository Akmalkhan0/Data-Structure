#include <stdio.h>
#include <malloc.h>

 void merge(int a[], int p, int q, int r)
  {

        int n1 = q - p + 1, n2 = r - q;
        int i, j, k;
        int *l, *ir;
        l = (int *)malloc(sizeof(int)* (n1 + 1));
        ir = (int *)malloc(sizeof(int) * (n2 + 1));

        j = 0;

        for (i = p ; i <= q ; i++)
            l[j++] = a[i];

        j = 0;

        for (i = q + 1 ; i <= r ; i++)
            ir[j++] = a[i];

        i = 0, j = 0;

        for (k = p ; i<n1 && j<n2 ; k++)
        {
            if (l[i] <= ir[j])
            {
                a[k] = l[i];
                i++;
            }
            else
            {
                a[k] = ir[j];
                j++;
            }
        }

        while(i<n1)
            a[k++] = l[i++];

        while(j<n2)
            a[k++] = ir[j++];

        free(l);
        free(ir);
  }

  void m_s(int a[], int p, int last)
  {
        int q;
        if (p < last)
        {
            q = (p + last) / 2;
            m_s(a, p, q);
            m_s(a, q + 1, last);
            merge(a, p, q, last);
        }
  }
  void arr_in(int a[], int n)
  {
        int i;
        for (i = 0; i < n; i++)
        {
            printf("Enter %d Element: ", i);
            scanf("%d", &a[i]);
        }
  }

 void arr_out(int a[], int n)
  {
        int i;
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
  }

 int main()
  {
        int *a, n;
        printf("Enter the size of Array: ");
        scanf("%d", &n);

        a = (int *)malloc(sizeof(int) * n);

        arr_in(a, n);

        m_s(a, 0, n-1);

        arr_out(a, n);

        free(a);
        return 0;
  }
