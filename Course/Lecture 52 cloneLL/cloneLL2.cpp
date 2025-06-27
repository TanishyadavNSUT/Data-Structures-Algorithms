class Solution
{
private:
    void Insertattail(Node *&head, Node *&tail, int d)
    {
        Node *node = new Node(d);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

public:
    Node *copyList(Node *head)
    {
        // step1: create a clone list
        Node *clonehead = NULL;
        Node *clonetail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            Insertattail(clonehead, clonetail, temp->data);
            temp = temp->next;
        }

        // step2: insert clone node in between original list

        Node *original = head;
        Node *clone = clonehead;
        while (original != NULL && clone != NULL)
        {
            Node *next = original->next;
            original->next = clone;
            original = next;

            if (original != NULL)
            {
                next = clone->next;
                clone->next = original;
                clone = next;
            }
        }

        // step3: add random pointers
        temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL && temp->arb != NULL)
            {
                temp->next->arb = temp->arb->next;
            }
            temp = temp->next->next;
        }

        // step4: remove clone nodes from original list
        original = head;
        clone = clonehead;
        while (original != NULL && clone != NULL)
        {
            original->next = clone->next;
            original = original->next;
            if (original != NULL)
            {
                clone->next = original->next;
            }
            clone = clone->next;
        }

        // step5: return ans
        return clonehead;
    }
};