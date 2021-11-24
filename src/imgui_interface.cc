
#include "imgui_interface.h"

void ImGuiInit(SDL_Window* window, SDL_Renderer* renderer){
	ImGui::CreateContext();
  ImGui_ImplSDL2_InitForSDLRenderer(window);
  ImGui_ImplSDLRenderer_Init(renderer);
  ImGui::SetNextWindowSize(ImVec2(320, 400));
}

void ImGuiRenderInit(SDL_Window* window){
  ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(window);
  ImGui::NewFrame();
}

void ImGuiRenderClear(){
  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiEvent(SDL_Event* event)
{
  ImGui_ImplSDL2_ProcessEvent(event);
}

void ImGuiExit(){
  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
}

void ImGuiShowData(Database* database, Info** info){

  static bool open = false;

  ImGui::Begin("SQL Window", nullptr);

  ImGui::Text("Database status:"); 
  ImGui::SameLine();
  ImGui::TextColored(ImVec4(0,1,0,1), "%s", open ? "Open" : "Close"); 
  ImGui::SameLine();

  if(ImGui::SmallButton(open ? " Close Test Database " : " Open Test Database ")){
    if(!open){
      SQLInit(database, info, "../data/test.db");
      open = true;
    }
    else{
      SQLClose(database);
      open = false;
    }
  }

  if(open){
    ImGui::InputText("Query", database->sql_query, kQuerySize);
    ImGui::SameLine();
    if(ImGui::Button("Execute")){
      SQLExecute(database, info);
    }
    ShowTableData(info);  
  }

  ImGui::End();
}

void ShowTableData(Info** head){

  if(nullptr != *head){

    for(Info* node = *head; node != nullptr; node = node->next){
      if(ImGui::CollapsingHeader(node->value)){
        ImGui::Text("Name: %s", node->colname);
        ImGui::Text("Value: %s", node->value);
      }
    }
    ImGui::Spacing();
  }
  else return;

}

