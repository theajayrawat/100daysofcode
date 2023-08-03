// Link:https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

node *partition(node *head, node *tail)
{
    node *pivot = head;
    node *curr = head;
    node *nex = curr->next;
    while (nex != tail)
    {
        if (pivot->data > nex->data)
        {
            swap(curr->next->data, nex->data);
            curr = curr->next;
        }
        nex = nex->next;
    }
    swap(pivot->data, curr->data);
    return curr;
}
void sort(node *head, node *tail)
{
    if (head == NULL || head == tail)
    {
        return;
    }
    node *p = partition(head, tail);
    node *temp = p->next;
    sort(head, p);
    sort(temp, tail);
}
void quickSort(struct node **headRef)
{
    node *head = *headRef;
    sort(head, NULL);
}