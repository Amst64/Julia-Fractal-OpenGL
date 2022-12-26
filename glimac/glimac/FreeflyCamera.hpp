namespace glimac {

class FreeflyCamera {
private:
    glm::vec3 m_Position;
    float m_fPhi;
    float m_fTheta;

    glm::vec3 m_FrontVector;
    glm::vec3 m_LeftVector;
    glm::vec3 m_UpVector;

    void computeDirectionVectors(){
        m_FrontVector = glm::vec3(glm::cos(m_fTheta) * glm::sin(m_fPhi), glm::sin(m_fTheta), glm::cos(m_fTheta) * glm::cos(m_fPhi));
        m_LeftVector = glm::vec3(glm::sin(m_fPhi + (glm::pi<float>()/2)), 0, glm::cos(m_fPhi + (glm::pi<float>()/2)));
        m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
    }

public:
    FreeflyCamera()
        : m_Position{glm::vec3(0, 0, 0)}, m_fPhi{glm::pi<float>()}, m_fTheta{0}
    {
        computeDirectionVectors();
    }

    void printValues() {
        std::cout << "Camera phi : " << m_fPhi << std::endl;
        std::cout << "Camera theta : " << m_fTheta << std::endl;
    }

    void moveLeft(float t){
        m_Position += t*m_LeftVector;
        computeDirectionVectors();
    }
    
    void moveFront(float t){
        m_Position += t*m_FrontVector;
        computeDirectionVectors();
    }

    void rotateLeft(float degrees){
        float angle = glm::radians(degrees);
        m_fPhi += angle;
        computeDirectionVectors();
    }

    void rotateUp(float degrees){
        float angle = glm::radians(degrees);
        m_fTheta += angle;
        computeDirectionVectors();
    }

    glm::mat4 getViewMatrix() const
    {
        glm::vec3 view = m_Position + m_FrontVector;
        return glm::lookAt(m_Position, view, m_UpVector);
    }
};
}