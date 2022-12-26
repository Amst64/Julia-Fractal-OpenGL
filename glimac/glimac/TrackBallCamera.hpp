
namespace glimac {

class TrackBallCamera {
private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;

public:
    TrackBallCamera()
        : m_fDistance{5.0f}, m_fAngleX{0}, m_fAngleY{0}
    {
    }

    void moveFront(float delta)
    {
        m_fDistance += delta;
    }

    void rotateLeft(float degrees)
    {
        m_fAngleX += glm::radians(degrees);
    }

    void rotateUp(float degrees)
    {
        m_fAngleY += glm::radians(degrees);
    }

    void printValues() const
    {
        std::cout << "camera distance : " << m_fDistance << std::endl;
        std::cout << "camera angleX : " << m_fAngleX << std::endl;
        std::cout << "camera angleY : " << m_fAngleY << std::endl;
    }

    glm::mat4 getViewMatrix() const
    {
        glm::mat4 ViewMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, m_fDistance));
        ViewMatrix           = glm::rotate(ViewMatrix, m_fAngleX, glm::vec3(0, 1, 0));
        ViewMatrix           = glm::rotate(ViewMatrix, m_fAngleY, glm::vec3(1, 0, 0));

        return ViewMatrix;
    }
};
}
    