class RectangularVectors
{
public:
    static std::vector<std::vector<int>> ReturnRectangularIntVector(int size1, int size2)
    {
        std::vector<std::vector<int>> newVector(size1);
        for (int vector1 = 0; vector1 < size1; vector1++)
        {
            newVector[vector1] = std::vector<int>(size2);
        }

        return newVector;
    }
};