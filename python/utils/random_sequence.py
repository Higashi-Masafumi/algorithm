import random


def random_sequence(length: int = 1000) -> list[int]:
    """ランダムな整数列を生成する

    Args:
        length (int, optional): 生成する整数列の長さ. Defaults to 1000.

    Returns:
        list[int]: 生成された整数列

    Examples:
        >>> random_sequence(10)
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        >>> random_sequence(10)
        [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    """
    seq = random.sample(list(range(length)), length)
    return seq
