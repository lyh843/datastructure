class double_list_node:
    """
    双向
    """
    def __init__(self, value = None, prev = None, next = None):
        self.value = value
        self.prev = prev
        self.next = next

class double_list:
    """
    双向循环列表
    """
    def __init__(self):
        self.fake_head = double_list_node()
        self.fake_head.prev = self.fake_head.next = self.fake_head
        self.len = 0
        