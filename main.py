from math import sqrt


def moment_centralny(data, l):
    m = 0
    n = len(data)
    srednia = sum(data) / n
    for liczba in data:
        m += (liczba - srednia) ** l

    m /= n
    return m


def moment_zwykly(data, l):
    m = 0
    n = len(data)
    for liczba in data:
        m += liczba ** l

    m /= n
    return m


def odchylenie_standardowe(data):
    s = 0
    n = len(data)
    srednia = sum(data) / n

    for liczba in data:
        s += (liczba - srednia) ** 2

    s /= n
    return sqrt(s)


def odchylenie_przecietne(data):
    d = 0
    n = len(data)
    srednia = sum(data) / n

    for liczba in data:
        d += abs(liczba - srednia)

    d /= n
    return d


def main():
    with open('100liczb.txt', 'r') as inputFile:
        lines = inputFile.readlines()

    stoliczb = [float(line.strip()) for line in lines]

    print('Moment centralny l=1:', moment_centralny(stoliczb, 1))
    print('Moment centralny l=2:', moment_centralny(stoliczb, 2))
    print('Moment zwykly l=1:', moment_zwykly(stoliczb, 1))
    print('Moment zwykly l=2:', moment_zwykly(stoliczb, 2))
    print('Odchylenie standardowe:', odchylenie_standardowe(stoliczb))
    print('Odchylenie przecietne:', odchylenie_przecietne(stoliczb))


if __name__ == '__main__':
    main()
