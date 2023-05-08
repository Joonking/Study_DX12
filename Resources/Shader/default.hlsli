



//Constant Buffer를 사용할건데 레지스터는 b0과 b1을 사용할거다
cbuffer TEST_B0 : register(b0)
{
    float4 offset0;
};

cbuffer TEST_B1 : register(b1)
{
    float4 offset1;
};


//vs단계에서 사용할 것들을 해당 자료형으로 받음. 
struct VS_IN
{
    float3 pos : POSITION;
    float4 color : COLOR;
};

//vs단계에서 나온 결과물을 담을 자료형 
struct VS_OUT
{
    float4 pos : SV_Position;
    float4 color : COLOR;
};

//VS(Vertex Shader)단계에서 뭘해야할지에 대해
//vs단계는 정점을 어떻게 변화할지를 정하는 단계
VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT) 0;

    //input으로 들어온 3가지의 값(float3)은 그대로 넣어주고, 마지막 값만 1로 채워서
    //output.pos에 넣어줘라.
    output.pos = float4(input.pos, 1.f);
    output.pos += offset0; 
    
    output.color = input.color;
    output.color += offset1;

    return output;
}

//PS(Pixel Shader) 단계에서 뭘 해야할지에 대해
//ps단계는 색상을 정해주는 단계임.
float4 PS_Main(VS_OUT input) : SV_Target
{
    return input.color;
}