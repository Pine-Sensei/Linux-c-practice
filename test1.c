    if (n == where+how)
    {
        return 0;
    }
    else
    {
        if (now == how)
        {
            for(int i = where; i < where+how; i++)
            {
                printf("%d\t", a[i]);
            }
            printf("\n");
        }
        else
        {
            for(int i = where; i < n; i++)
            {
                swap(i, now);
                if ()
                    combination(n, where, now+1, how);
                else
                    combination(n, where+1, 0, how);
                swap(i, now);
            }
        }
    }